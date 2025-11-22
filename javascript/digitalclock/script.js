function clockupdate(){

  let date = new Date();
  let hours = date.getHours().toString().padStart(2, '0');
  let minutes = date.getMinutes().toString().padStart(2, '0');
  let seconds = date.getSeconds().toString().padStart(2, '0');
  let hour = hours % 12 || 12;
  let meridian = hours >= 12 ? 'PM' : 'AM';
  let time = `${hour}:${minutes}:${seconds} ${meridian}`;
  document.getElementById('clock').innerText = time;

}

clockupdate();
setInterval(clockupdate, 1000);