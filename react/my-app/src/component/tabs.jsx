import { useState } from "react";
import './style.css'

function Tabs({ tabcontent, onchange = () => { } }) {
    const [currentIndex, setCurrentIndex] = useState(0);

    function handleindex(idx) {
        setCurrentIndex(idx);
        onchange(idx);
    }

    return (
        <div className="wrapper">
            <div className="tabstitle">
                {tabcontent.map((item, index) => (
                    <div
                        key={index}
                        className="label"
                        onClick={() => handleindex(index)}
                    >
                        {item.label}
                    </div>
                ))}
            </div>
            <div className="content">
                {tabcontent[currentIndex]?.content && (
                    <span>{tabcontent[currentIndex].content}</span>
                )}
            </div>
        </div>
    );
}

export default Tabs;