const inc=document.getElementById("inc");
const dec=document.getElementById("dec");
const reset=document.getElementById("reset");

let count = document.getElementById("count").textContent;
count=Number(count);

const countdisplay = document.getElementById("count");


inc.onclick=function(){
    
    count++;
    count%=11;
    countdisplay.textContent=count;

}

dec.onclick=function(){
     
    count--;
    count%=11;
    countdisplay.textContent=count;
}

reset.onclick=function(){
    count=0;
    countdisplay.textContent=count;
}