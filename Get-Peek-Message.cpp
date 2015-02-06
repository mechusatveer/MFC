Go to ParentGetMessage and PeekMessage are used to get a message from message
queue while PostMessage is used to post a message.The major difference between
GetMessage and PeekMessage is that GetMessage doesn't return until it finds a 
message to retrieve from the Message Queue and PeekMessage() returns immediately 
weather there are any messages or not.While PostMessage is used to post a message
to window and it returns immediately without waiting for the response. 

GetMessage:

a. It retrieves the message from the calling thread's message queue.
b. It blocks until it gets a message or an error occurs.
c. It can filter message as per specified filter.

Example:

Code:
BOOL bRet;
MSG msg;

while( (bRet = GetMessage( &msg, hWnd, 0, 0 )) != 0)
{ 
    if (bRet == -1)
    {
        // handle the error and possibly exit
    }
    else
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }
}
PeekMessage:
a. It checks for the message in the calling thread's message queue and it 
retrieves the message if any present.
b. As specified in the argument, it may or may not removes the message from message queue.
c. It returns immediately if there is no message found in the message queue. 
Hence it can be useful in some situation to process message in between lengthy operation.

Example:

Code:
HWND hwnd; 
MSG msg; 
 
while (PeekMessage(&msg, hwnd,  0, 0, PM_REMOVE)) 
{ 
     //handle message here...
}
