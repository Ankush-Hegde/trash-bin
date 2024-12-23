// 3. Handling Events

import React, {useState} from "react";

function Events() {
  const [value, setValue] = useState("");

  function handleChange(event) {
    setValue(event.target.value)
  }

  return (
    <>
    <h1>Welcome to the this Page</h1>
      <div><b>you typed :</b> {value}</div>

      <input onChange={handleChange} placeholder="type here"></input>
    </>
  )

}

export default Events