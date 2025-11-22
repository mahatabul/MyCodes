const weatherinput = document.querySelector(".weatherinput");
const cityinput = document.querySelector(".cityinput");
const resultdisplay = document.querySelector(".resultdisplay");

const apikey = import.meta.env.VITE_API_KEY;





weatherinput.addEventListener("submit", async (event) => {
  event.preventDefault();

  const cityname = cityinput.value;

  if (cityname) {
    const city = await getweatherinfo(cityname);

    displayweatherinfo(city);
  } else {
    displayError("Please enter a city");
  }
});

async function getweatherinfo(city) {
  const apicall = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apikey}`;
  const response = await fetch(apicall);

  if (!response.ok) {
    throw new Error("Could not fetch data");
  }

  return await response.json();
}
function displayweatherinfo(data) {
  const {
    name: city,
    main: { temp, humidity, temp_max, temp_min },
    weather: [{ id, main, description, icon }],
  } = data;

  console.log(data);

  const emoji = getweatheremoji(icon);
  let tempp_max=  (temp_max-273.15).toFixed(0);
  let tempp_min=  (temp_min-273.15).toFixed(0);

  resultdisplay.innerHTML = "";
  resultdisplay.classList.remove("hidden");
  resultdisplay.style.display = "flex";

  // city name
  const cityname = document.createElement("h1");
  cityname.textContent = city;
  cityname.classList.add("city");
  resultdisplay.appendChild(cityname);

  // temprature display
  const tempdisplay = document.createElement("p");
  tempdisplay.textContent = `${(temp - 273.15).toFixed(1)}°C`;

  tempdisplay.classList.add("temp");
  resultdisplay.appendChild(tempdisplay);

  // humidity display
  const humiditydisplay = document.createElement("p");
  humiditydisplay.textContent = `Humidity: ${humidity}%`;
  humiditydisplay.classList.add("humidity");
  resultdisplay.appendChild(humiditydisplay);

  //  description
  const descriptiondisplay = document.createElement("p");
  descriptiondisplay.textContent = `${description} (${tempp_max}°C/${tempp_min}°C)`;
  descriptiondisplay.classList.add("weather");
  resultdisplay.appendChild(descriptiondisplay);

  //  emoji
  const emojidisplay = document.createElement("img");
  emojidisplay.src = emoji;
  emojidisplay.classList.add("emoji");
  resultdisplay.appendChild(emojidisplay);
}
function getweatheremoji(icon) {
  const imgsrc = `https://openweathermap.org/img/wn/${icon}@2x.png`;
  return imgsrc;
}

function displayError(message) {
  const error = document.createElement("p");
  error.textContent = message;
  error.classList.add("errordisplay");

  resultdisplay.innerHTML = "";
  resultdisplay.classList.remove("hidden");
  resultdisplay.style.display = "flex";
  resultdisplay.appendChild(error);
}
