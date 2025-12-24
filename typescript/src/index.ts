const menu = [
    { name: "pizza1", price: 12 },
    { name: "pizza2", price: 22 },
    { name: "pizza3", price: 32 },
]
const order = []
let cash = 10;
let nextorder = 1

function addnewPizza(pizza) {
    menu.push(pizza)
}
function placeorder(piname) {
    const selectedpizza = menu.find(pobj => pobj.name == piname)
    if (!selectedpizza) {
        return
    }
    cash += selectedpizza.price;
}