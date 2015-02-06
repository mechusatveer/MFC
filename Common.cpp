
https://vcpptips.wordpress.com/vc-interview-questions/

Starting point of windows application?

WinMain() is the entry point of Windows applications.

Parameters of WinMain()

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
LPSTR lpszCmdLine, int nCmdShow)

hInstance – The handle of the currently running module.
hPrevInstance – A handle to a previous instance of the application. For a Win32-based application, this parameter is always NULL.
lpCmdLine – Points to a null-terminated string specifying the command line for the application.
nCmdShow – Specifies how the main window of a GUI application would be shown.

What is windows programming? How it’s working?

Windows is an event driven programming mechanism, in which applications respond to events by processing messages sent by the operating system. An event could be a keystroke, a mouse click, or a command for a window to repaint itself, among other things. The entry point for a Windows program is a function named WinMain, but most of the action takes place in a function known as the window procedure. The window procedure processes messages sent to the window. WinMain creates that window and then enters a message loop, alternately retrieving messages and dispatching them to the window procedure. Messages wait in a message queue until they are retrieved.

Startup of a Simple Windows Program?

LONG WINAPI WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
LPSTR lpszCmdLine, int nCmdShow)
{
WNDCLASS wc;
HWND hwnd;
MSG msg;

//Fill WNDCLASS structure

RegisterClass (&wc);
hwnd = CreateWindow(…);

ShowWindow (hwnd, nCmdShow);
UpdateWindow (hwnd);

while (GetMessage (&msg, NULL, 0, 0)) {
TranslateMessage (&msg);
DispatchMessage (&msg);
}
return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam,
LPARAM lParam)
{
}

What is MFC?

MFC is the C++ class library Microsoft provides to place an object-oriented wrapper around the Windows API. MFC is also an application framework. More than merely a collection of classes, MFC helps define the structure of an application and handles many routine chores on the application’s behalf. Starting with CWinApp, the class that represents the application itself, MFC encapsulates virtually every aspect of a program’s operation. The framework supplies the WinMain function, and WinMain in turn calls the application object’s member functions to make the program go. One of the CWinApp member functions called by WinMain—Run—provides the message loop that pumps messages to the application’s window. The framework also provides abstractions that go above and beyond what the Windows API has to offer.

What is an application framework?

The application framework is a collection of classes and the structure of an application which handles many routine chores on the application’s behalf. The framework also provides abstractions that go above and beyond what the Windows API has to offer.

MFC is an application framework – it acts as object oriented wrapper around the Windows API.

Principle base class in MFC?

CObject is the principal base class for the Microsoft Foundation Class Library. The majority of MFC classes are derived, either directly or indirectly, from CObject.

CObject provides basic services, including
– Serialization support
– Run-time class information
– Object diagnostic output
– Compatibility with collection classes

Difference between ASSERT and VERIFY?

ASSERT evaluates the expression only in the debug version and will throw an exception if the result is 0 and the program termintes.
VERIFY evalutes the expression in Debug and Release version also and if the result is 0, will throw an exception only in Debug mode.

What is the difference between PostMessage and SendMessage?

The PostMessage function places (posts) a message in the message queue associated with the thread that created the specified window and returns without waiting for the thread to process the message.

The SendMessage function sends the specified message to a window or windows. It calls the window procedure for the specified window and does not return until the window procedure has processed the message.

What is the difference between PeekMessage and GetMessage?

You can use the PeekMessage function to examine a message queue during a lengthy operation. PeekMessage is similar to the GetMessage function, both check a message queue for a message that matches the filter criteria and then copy the message to an MSG structure. The main difference between the two functions is that GetMessage does not return until a message matching the filter criteria is placed in the queue, whereas PeekMessage returns immediately regardless of whether a message is in the queue.

What is the difference between hInstance and hWnd?

hWnd is the window’s handle and is how the OS defines a window when talking about it inside the PC.
hInstance is the OS’s handle for the program when running it.

What is the difference between Modal and Modeless Dialog?

Modal dialog box captures the message loop, whereas model less does not. Call DoModal to create the dialog window and its controls for a modal dialog. If you wish to create a modeless dialog, call Create in the constructor of your Cdialog class.
Example for Model Dialog is Save, Save As Dialog in MS -Word.
Example for Modeless Dialog is Find,Replace dialogs.

What is the use of CCmdTarget?

It is the base class for the MFC library message map architecture. Which maps commands/messages to the member functions to handle them. Classes derived from this are CWnd,CWinApp,CFrameWnd,CView, CDocument

What is the difference between hinsrtance and hprevinstance in WinMain function?

hInstance : will be having the handle of the current instance
hPrevInctance : will be having the handle of last instance, hPrevInstance is NULL if only one instance is running

Describe the Document/View architecture.

In MFC 1.0, an application had two principal components: an application object representing the application itself and a window object representing the application’s window. The application object’s primary duty was to create a window, and the window in turn processed messages.

MFC 2.0 changed the way Windows applications are written by introducing the document/view architecture. In a document/view application, the application’s data is represented by a document object and views of that data are represented by view objects. Documents and views work together to process the user’s input and draw textual and graphical representations of the resulting data. MFC’s CDocument class is the base class for document objects, and CView is the base class for view objects. The application’s main window, whose behavior is modeled in MFC’s CFrameWnd and CMDIFrameWnd classes, is no longer the focal point for message processing but serves primarily as a container for views, toolbars, status bars, and other user interface objects.
MFC supports two types of document/view applications. Single document interface (SDI) applications support just one open document at a time. Multiple document interface (MDI) applications permit two or more documents to be open concurrently and also support multiple views of a given document

What is document?

In a document/view application, data is stored in a document object. The document object is created when the framework instantiates a class derived from CDocument. It is an abstract representation of a program’s data that draws a clear boundary between how the data is stored and how it is presented to the user. That means the sole purpose of a document object is to manage an application’s data.

What is view?

View objects exist for two purposes: to render visual representations of a document on the screen and to translate the user’s input—particularly mouse and keyboard messages—into commands that operate on the document’s data. Thus, documents and views are tightly interrelated, and information flows between them in both directions.

Distinguish between Window’s OnPaint and View’s OnDraw overridable functions?

Window’s OnPaint function executes corresponding to each WM_PAINT messages. But in the case of document-view architecture when a view receives a WM_PAINT message, it invokes view’s OnDraw function. Actually the framework fields the WM_PAINT message, creates a CPaintDC object, and calls the view’s OnDraw function with a pointer to the CPaintDC object.
The fact that the view doesn’t have to construct its own device context object is a minor convenience. The real reason the framework uses OnDraw is so that the same code can be used for output to a window, for printing, and for print previewing. When a WM_PAINT message arrives, the framework passes the view a pointer to a screen device context so that output will go to the window. When a document is printed, the framework calls the same OnDraw function and passes it a pointer to a printer device context.

What is command routing?

One of the most remarkable features of the document/view architecture is that an application can handle command messages almost anywhere. Command messages is MFC’s term for the WM_COMMAND messages that are generated when items are selected from menus, keyboard accelerators are pressed, and toolbar buttons are clicked. The frame window is the physical recipient of most command messages, but command messages can be handled in the view class, the document class, or even the application class by simply including entries for the messages you want to handle in the class’s message map. The flow of command messages from Active View to DefWindowProc is know as command routine.

ActiveView -> Active View’s Doc -> Document Template -> Frame Window -> Application Object -> DefWindowProc

How Message Map works in an MFC application?

The message map functionality in an MFC application works by the support of 3 Macros, DECLARE_MESSAGE_MAP, BEGIN_MESSAGE_MAP, and END_MESSAGE_MAP and the WindowProc function implementation.

MFC’s DECLARE_MESSAGE_MAP macro adds three members to the class declaration: a private array of AFX_MSGMAP_ENTRY structures named _messageEntries that contains information correlating messages and message handlers; a static AFX_MSGMAP structure named messageMap that contains a pointer to the class’s _messageEntries array and a pointer to the base class’s messageMap structure; and a virtual function named GetMessageMap that returns messageMap’s address. BEGIN_MESSAGE_MAP contains the implementation for the GetMessageMap function and code to initialize the messageMap structure. The macros that appear between BEGIN_MESSAGE_MAP and END_MESSAGE_MAP fill in the _messageEntries array, and END_MESSAGE_MAP marks the end of the array with a NULL entry.

Thus corresponding to each message a class can traverse through it’s and base classes message map entries to find a handler till it to reach the DefWindowProc.

What is the difference between thread and process?

In the Microsoft Win32 environment, every running application constitutes a process and every process contains one or more threads of execution. A thread is a path of execution through a program’s code, plus a set of resources (stack, register state, and so on) assigned by the operating system.
