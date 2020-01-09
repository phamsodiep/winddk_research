#include <ntddk.h>



NTSTATUS Dispatch(__in PDEVICE_OBJECT DeviceObject, __in PIRP Irp) {
  return STATUS_SUCCESS;
}


NTSTATUS
DriverEntry(
    __in PDRIVER_OBJECT     DriverObject,
    __in PUNICODE_STRING    RegistryPath
)
{
  int i;

  for (i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++) {
    DriverObject->MajorFunction[i] = Dispatch;
  }

  //https://docs.microsoft.com/en-us/windows-hardware/drivers/install/inf-manufacturer-section
      //https://docs.microsoft.com/en-us/windows-hardware/drivers/install/inf-models-section


  //DriverObject->DriverExtension->AddDevice = BusAddDevice;
  //DriverObject->MajorFunction[IRP_MJ_PNP] = Dispatch;
  //DriverObject->MajorFunction[IRP_MJ_POWER] = Dispatch;
  //DriverObject->MajorFunction[IRP_MJ_CREATE] = Dispatch;
  //DriverObject->MajorFunction[IRP_MJ_CLOSE] = Dispatch;
  //DriverObject->MajorFunction[IRP_MJ_SYSTEM_CONTROL] = Dispatch;
  //DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = Dispatch;
  //DriverObject->MajorFunction[IRP_MJ_SCSI] = Dispatch;
  //DriverObject->DriverUnload = Unload;


  return STATUS_SUCCESS;
}

