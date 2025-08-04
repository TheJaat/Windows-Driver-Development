// Include the basic NT Driver Development Kit header
// This provides core Windows kernel-mode definitions and functions
#include <ntddk.h>

// Include the Windows Driver Framework header (optional in this case, but required for KMDF drivers)
#include <wdf.h>

// ------------------------------------------------------
// DriverUnload: This function is called when the driver
// is being unloaded from the system.
// ------------------------------------------------------
VOID DriverUnload(PDRIVER_OBJECT DriverObject)
{
    // This macro just tells the compiler we are not using this parameter
    UNREFERENCED_PARAMETER(DriverObject);

    // Print a debug message to the kernel debugger or DebugView
    DbgPrint("WFP Driver: Unload called.\n");
}

// ------------------------------------------------------
// DriverEntry: This is the main entry point for the driver.
// It is called by the OS when the driver is loaded.
// ------------------------------------------------------
NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
    // We are not using the registry path in this driver, so we mark it as unreferenced
    UNREFERENCED_PARAMETER(RegistryPath);

    // Register the unload routine so Windows knows which function to call
    // when the driver is being removed
    DriverObject->DriverUnload = DriverUnload;

    // Print a message to the debugger to show that the driver has loaded
    DbgPrint("WFP Driver: Hello World from WFP driver!\n");

    // Return STATUS_SUCCESS to tell the OS the driver loaded successfully
    return STATUS_SUCCESS;
}
