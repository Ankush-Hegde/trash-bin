// 4. Conditional Rendering

import React, {useState} from "react";

import Button from "../components/Button"

function ConditionalRendering() {

  const [isLoggedIn, setIsLoggedIn] = useState(false);

  return (
    <>
      <h1>Welcome to the Home Page</h1>

      {isLoggedIn ? 
        (
          <div>
            loggedIn
          </div>
        ) 
        : 
        (
          <div>
            notloggedIn
          </div>
        )
      }

      <Button onClick={() => setIsLoggedIn(!isLoggedIn)}>{isLoggedIn ? 
          "logOut"
        : 
          "logIn"
      }</Button>

    </>
  )
}

export default ConditionalRendering