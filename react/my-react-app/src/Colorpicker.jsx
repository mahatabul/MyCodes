import React, { useState } from "react";

function ColorPicker() {
    const [color, setColor] = useState("#000000");
    const handleColorChange = (event) => {
        setColor(event.target.value);
    };
    return (

        <>

            <div className="container"><h1>Color Picker </h1>
                <div className="box" style={{ background: color }}>
                    {color}
                </div>
                <p>Pick Color:</p>
                <input type="color" value={color} onChange={handleColorChange} /></div>

        </>

    );

}

export default ColorPicker