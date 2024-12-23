// 5. Lists and Keys

import React from "react";

function Map() {
  const fruits = ["Apple", "Banana", "Cherry", "Date"];

  return (
    <>
      {fruits.map((value, index) => (<div key={index}>{value}</div>))}
    </>
  )
}

export default Map;