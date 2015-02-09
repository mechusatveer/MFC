#include <Windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;

	if(argc > 1) {
		printf("Argument %s\n", argv[1]);
		printf("Starting child process\n");

		memset(&startupInfo, 0, sizeof(startupInfo));
		memset(&processInfo, 0, sizeof(processInfo));

		startupInfo.cb = sizeof(startupInfo);

		if(CreateProcess(argv[0], 0, 0, 0, 0, 0, 0, 0, 
				&startupInfo, &processInfo) == 0)
		{
			printf(" Error %d\n", GetLastError());
		}
		//hProcess
		WaitForSingleObject(processInfo.hProcess, INFINITE);
	}
	else {
		printf("No argument\n");
	}

	getchar();

	return 0;
}



The handle of the created process is returned in processInfo.hProcess. This handle is used to 
call WaitForSingleObject(). This call returns when the child process exits. The child process
did not have any argument in the example, so the "No argument" was the output from the child 
process while the "Argument myArgument" was from the main process.

#include <Windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;

	if(argc == 1) {
		char Args[256];
		sprintf_s(Args, "dummyArgs %s", argv[0]);
		memset(&startupInfo, 0, sizeof(startupInfo));
		memset(&processInfo, 0, sizeof(processInfo));

		startupInfo.cb = sizeof(startupInfo);

		if(CreateProcess(argv[0], Args, 
			0, 0, 0, 0, 0, 0, &startupInfo, &processInfo) == 0)
		{
			printf(" Error %d\n", GetLastError());
		}
		WaitForSingleObject(processInfo.hProcess, INFINITE);
	}
	else {
		printf("Argument %s\n", argv[1]);
	}

	getchar();

	return 0;
}


#include <Windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;
	HANDLE fileHandle;
	char ID[] = TEXT("Local\\sharedmemory");
	char *memory;

	if(argc == 1) {
		fileHandle = CreateFileMapping(INVALID_HANDLE_VALUE,
					NULL, PAGE_READWRITE, 0, 1024, ID);
		memory = (char*)MapViewOfFile(fileHandle, 
					FILE_MAP_ALL_ACCESS, 0, 0, 0);
		sprintf_s(memory, 1024, "%s", "Data from first process");
		printf("First process: %s\n", memory);

		memset(&startupInfo, 0, sizeof(startupInfo));
		memset(&processInfo, 0, sizeof(processInfo));
		startupInfo.cb = sizeof(startupInfo);

		char Args[256];
		sprintf_s(Args, "dummyArgs %s", argv[0]);

		CreateProcess(argv[0], Args, 
			0, 0, 0, 0, 0, 0, &startupInfo, &processInfo);
		WaitForSingleObject(processInfo.hProcess, INFINITE);

		UnmapViewOfFile(memory);
		CloseHandle(fileHandle);
	}
	else {
		fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, ID);
		memory = (char*)MapViewOfFile(fileHandle, 
					FILE_MAP_ALL_ACCESS, 0, 0, 0);

		printf("Second process %s\n", memory);

		UnmapViewOfFile(memory);
		CloseHandle(fileHandle);
	}

	getchar();

	return 0;
}

