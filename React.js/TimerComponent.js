// 7.1/3 useeffect
import React, { useState, useEffect } from "react";

function TimerComponent() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    const interval = setInterval(() => {
      setCount((prevCount) => prevCount + 1);
    }, 1000);

    return () => clearInterval(interval); // Cleanup the interval on unmount
  }, []); // Runs only once on mount

  return <p>Timer: {count} seconds</p>;
}

export default TimerComponent;