// 2. State Management with useState

import { react, useState } from "react";

function StateManagementWithUseState() {
  const [inc, setInc] = useState(0);

  return (
    <>
      <h1>value is {inc}</h1>
      <button onClick={() => setInc(inc + 1)}>Increment</button>
      <button onClick={() => setInc(inc - 1)}>Decrement</button>
    </>
  )
}

export default StateManagementWithUseState