// function generatepassword(
//     length,
//     includeLowercase = true,
//     includeUppercase = true,
//     includesymbols = true,
//     includenumbers = true
// ) {
//     uppercaseletters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     lowercaseletters = "abcdefghijkmnopqrstuvwxyz";
//     symbols = "!@#$%^&*(){}[]_-";
//     numbers = "1234567890";

//     let str = "";
//     let pass = "";

//     if (includeUppercase) {
//         str += uppercaseletters;
//         pass +=
//             uppercaseletters[Math.floor(Math.random() * uppercaseletters.length)];
//     }
//     if (includeLowercase) {
//         str += lowercaseletters;
//         pass +=
//             lowercaseletters[Math.floor(Math.random() * lowercaseletters.length)];
//     }
//     if (includesymbols) {
//         str += symbols;
//         pass += symbols[Math.floor(Math.random() * symbols.length)];
//     }
//     if (includenumbers) {
//         str += numbers;
//         pass += numbers[Math.floor(Math.random() * numbers.length)];
//     }
//     let x = pass.length;
//     for (i = 1; i <= length - x; i++) {
//         pass += str[Math.floor(Math.random() * str.length)];
//     }


//     pass = pass.split('');
//     for (let i = 0; i < length; i++) {
//         j = Math.floor(Math.random() * length);

//         [pass[i], pass[j]] = [pass[j], pass[i]];
//     }
//     pass = pass.join('')

//     return pass;
// }

// const length = 12;
// const includeLowercase = true;
// const includeUppercase = true;
// const includesymbols = true;
// const includenumbers = true;

// const pass = generatepassword(
//     length,
//     includeLowercase,
//     includeUppercase,
//     includesymbols,
//     includenumbers
// );

// console.log(`Generated password ${pass} and password length ${pass.length}`);

setTimeout(() => {
    console.log("Hello!");
}, 3000);