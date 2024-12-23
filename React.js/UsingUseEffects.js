// 7.3/3 use effect

import React, {useEffect, useState, useRef} from "react";

function UsingUseEffects() {
  const inputRef = useRef(null);
  const [message, setMessage] = useState("");

  useEffect(() => {
    console.log("Home component mounted!");
    setMessage("Welcome to the React World!"); // fetch data and set item
    inputRef.current.focus(); // used to focus on ref when rendered
  }, []);

  return (
    <div>
      <h1>{message}</h1>
      <input ref={inputRef} placeholder="I am focused on mount!" />
    </div>
  );
}

export default UsingUseEffects