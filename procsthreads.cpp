#include "procsthreads.h"
#include <iostream>
#include <thread>

#include <windows.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Part 1: Working with (child) processes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Example for creating a child process in a Windows environment
// see
// https://docs.microsoft.com/de-de/windows/win32/procthread/creating-processes
void example_win_process() {
  char cmdline[] = "tasklist.exe"; // command which will be executed as separate
                                   // child process

  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  // Start the child process.
  if (!CreateProcess(NULL,    // No module name (use command line)
                     cmdline, // Command line
                     NULL,    // Process handle not inheritable
                     NULL,    // Thread handle not inheritable
                     FALSE,   // Set handle inheritance to FALSE
                     0,       // No creation flags
                     NULL,    // Use parent's environment block
                     NULL,    // Use parent's starting directory
                     &si,     // Pointer to STARTUPINFO structure
                     &pi)     // Pointer to PROCESS_INFORMATION structure
  ) {
    std::cout << "CreateProcess failed - error code: " << GetLastError()
              << endl;
    return;
  }

  std::cout << "example_win_process() has created the child - waiting until "
               "child exits..."
            << std::endl;

  // Here, we could do some other work...

  // Wait until child process exits.
  WaitForSingleObject(pi.hProcess, INFINITE);
  std::cout << "child process has terminated." << std::endl;

  // Close process and thread handles.
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  std::cout << "example_win_process() is done." << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Part 2: Working with threads
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void thread_function(string id) {
  for (int i = 0; i < 10000; i++)
    std::cout << id;
}

void example_multithreads() {
  thread threadObj(thread_function, "A");
  for (int i = 0; i < 10000; i++)
    cout << "*";
  cout << endl
       << "example_main_thread has done its work - waiting for other thread.."
       << endl;
  threadObj.join();
  cout << endl << "example_main_thread() exit" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main method
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  // Note: uncomment the part that should be executed:
  // example_win_process();
  // example_multithreads();
  return 0;
}
