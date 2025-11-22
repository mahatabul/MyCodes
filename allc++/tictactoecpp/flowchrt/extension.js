const vscode = require('vscode');

function activate(context) {
    console.log('Extension "cpp-flowchart" is now active!');

    let disposable = vscode.commands.registerCommand('cpp-flowchart.generateFlowchart', () => {
        const editor = vscode.window.activeTextEditor;
        if (!editor || !editor.document.languageId.includes('cpp')) {
            vscode.window.showErrorMessage('Please open a C++ file (.cpp or .h).');
            return;
        }

        const code = editor.document.getText();
        const mermaidCode = generateMermaidFlowchart(code);

        // Debug: Log the generated Mermaid code to check what’s being produced
        console.log('Generated Mermaid Code:', mermaidCode);

        const panel = vscode.window.createWebviewPanel(
            'cppFlowchart',
            'C++ Flowchart',
            vscode.ViewColumn.Beside,
            { enableScripts: true }
        );

        panel.webview.html = getWebviewContent(mermaidCode);
    });

    context.subscriptions.push(disposable);
}

function generateMermaidFlowchart(code) {
    const lines = code.split('\n');
    let mermaid = 'graph TD;\n';
    let nodeId = 0;
    const nodes = [];
    const edges = [];

    for (const line of lines) {
        const trimmed = line.trim();

        // Match if-else statement
        const ifMatch = trimmed.match(/^if\s*\((.*?)\)/);
        if (ifMatch) {
            const condition = ifMatch[1];
            nodes.push(`N${nodeId}[Test Condition<br>${condition}]`);
            nodeId++;
            nodes.push(`N${nodeId}[Yes Branch]`);
            nodeId++;
            nodes.push(`N${nodeId}[No Branch]`);
            nodeId++;

            // Look for the else clause in the next lines
            let elseFound = false;
            for (let i = lines.indexOf(line) + 1; i < lines.length; i++) {
                if (lines[i].trim() === 'else') {
                    elseFound = true;
                    break;
                }
            }

            // Define edges
            edges.push(`N${nodeId - 3}-->|true|N${nodeId - 2}`); // Test -> Yes
            if (elseFound) {
                edges.push(`N${nodeId - 3}-->|false|N${nodeId - 1}`); // Test -> No
            } else {
                edges.push(`N${nodeId - 3}-->|false|N${nodeId - 1}`); // Test -> No (single if case)
            }
            break; // Handle one if-else for simplicity
        }

        // Match for loop (existing logic)
        const forMatch = trimmed.match(/^for\s*\((.*?);(.*?);(.*?)\)\s*{/);
        if (forMatch) {
            const [_, init, cond, update] = forMatch;
            nodes.push(`N${nodeId}[Initialization Expression<br>${init}]`);
            nodeId++;
            nodes.push(`N${nodeId}[Test Condition<br>${cond}]`);
            nodeId++;
            nodes.push(`N${nodeId}[for Loop Body]`);
            nodeId++;
            nodes.push(`N${nodeId}[Update Expression<br>${update}]`);
            nodeId++;
            nodes.push(`N${nodeId}[Loop Terminates]`);
            nodeId++;

            edges.push(`N0-->N1`); // Init -> Test
            edges.push(`N1-->|true|N2`); // Test true -> Body
            edges.push(`N1-->|false|N4`); // Test false -> Terminates
            edges.push(`N2-->N3`); // Body -> Update
            edges.push(`N3-->N1`); // Update -> Test (loop back)
            break; // Handle one for loop for simplicity
        }
    }

    // Combine nodes and edges
    return mermaid + nodes.join(';\n') + ';\n' + edges.join(';\n');
}

function getWebviewContent(mermaidCode) {
    return `
        <!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>C++ Flowchart</title>
            <script src="https://cdn.jsdelivr.net/npm/mermaid@10.9.0/dist/mermaid.min.js"></script>
            <style>
                .mermaid {
                    background-color: #e6f0fa;
                    padding: 20px;
                    border-radius: 10px;
                }
                .mermaid .node rect {
                    fill: #00c4cc;
                    stroke: #00a1a7;
                    stroke-width: 2px;
                    rx: 5px;
                    ry: 5px;
                }
                .mermaid .node polygon {
                    fill: #00c4cc;
                    stroke: #00a1a7;
                    stroke-width: 2px;
                }
                .mermaid .edgePath path {
                    stroke: #00a1a7;
                    stroke-width: 2px;
                }
                .mermaid text {
                    fill: #ffffff;
                    font-size: 14px;
                }
            </style>
        </head>
        <body>
            <div class="mermaid">${mermaidCode}</div>
            <script>
                mermaid.initialize({
                    startOnLoad: true,
                    theme: 'default',
                    flowchart: {
                        useMaxWidth: false,
                        htmlLabels: true
                    }
                });
            </script>
        </body>
        </html>
    `;
}

function deactivate() {}

module.exports = {
    activate,
    deactivate
};