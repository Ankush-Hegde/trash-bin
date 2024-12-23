Dim Message, Speak
Message=InputBox("Enter text","speak")
Set Speak=CreateObject("sapi.spvoice")
Speak.Speak Message