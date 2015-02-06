Go to ParentGetMessage and PeekMessage are used to get a message from message
queue while PostMessage is used to post a message.The major difference between
GetMessage and PeekMessage is that GetMessage doesn't return until it finds a 
message to retrieve from the Message Queue and PeekMessage() returns immediately 
weather there are any messages or not.While PostMessage is used to post a message
to window and it returns immediately without waiting for the response. 

