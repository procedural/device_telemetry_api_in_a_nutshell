#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum TelemetryDeviceStatus {
  TELEMETRY_DEVICE_STATUS_SUCCESS = 0,
  // ...
} TelemetryDeviceStatus;

typedef enum TelemetryType {
  TELEMETRY_TYPE_NONE = 0,
  TELEMETRY_TYPE_FOO  = 1,
  TELEMETRY_TYPE_BAR  = 2,
  // ...
} TelemetryType;

typedef enum TelemetryStatus {
  TELEMETRY_STATUS_VALID         = 0,
  TELEMETRY_STATUS_NOT_SUPPORTED =-1,
  // ...
} TelemetryStatus;

typedef struct TelemetryFoo {
  TelemetryStatus status;
  uint64_t        sampleTimeSeconds;
  uint64_t        sampleTimeNanoseconds;
  int             someTelemetryValue;
  // ...
} TelemetryFoo;

typedef struct TelemetryBar {
  TelemetryStatus status;
  uint64_t        sampleTimeSeconds;
  uint64_t        sampleTimeNanoseconds;
  int             someOtherTelemetryValue;
  // ...
} TelemetryBar;

typedef void (*TypeTelemetryCallback)(const void * deviceHandle, TelemetryType telemetryType, const void * telemetry);

TelemetryDeviceStatus getTelemetry(const void * deviceHandle, TelemetryType telemetryType, void * outTelemetry, TypeTelemetryCallback telemetryCallback);

#ifdef __cplusplus
}
#endif
