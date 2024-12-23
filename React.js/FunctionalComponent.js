// 1. Functional Components and JSX Basics
import React from "react";

function FunctionalComponent() {
  const message = "Welcome to the this Page";
  
  return (
    <div>
      <h1>{message}</h1>
      <p>This is Functional Component</p>
    </div>
  );
}

export default FunctionalComponent;