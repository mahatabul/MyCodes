import Tabs from "./tabs";

function Tabtest() {

    const tabs = [
        {
            label: "Tab 1",
            content: "This is from tab 1"
        },
        {
            label: "Tab 2",
            content: "This is from tab 2"
        },
        {
            label: "Tab 3",
            content: "This is from tab 3"
        }
    ]

    function handlechange(something) {
        console.log(something);
    }

    return (
        <Tabs tabcontent={tabs} onchange={handlechange} />
    );



}

export default Tabtest;