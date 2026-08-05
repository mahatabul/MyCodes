import { useState } from "react";
export default function Login() {
  const [count, setcount] = useState(0);

  const increseCount = () => {
    setcount((count) => count + 1);
  };
  return (
    <>
      <div>count:${count}</div>
      <button onClick={increseCount}>IN</button>
    </>
  );
}
