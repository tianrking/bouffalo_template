#ifndef UXR_CLIENT_PROFILE_TRANSPORT_CUSTOM_RISCV_TRANSPORT_H_
#define UXR_CLIENT_PROFILE_TRANSPORT_CUSTOM_RISCV_TRANSPORT_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct uxrUDPPlatform
{
    int fd;
} uxrUDPPlatform;

typedef struct uxrTCPPlatform
{
    int fd;
} uxrTCPPlatform;

typedef struct uxrSerialPlatform
{
    int fd;
} uxrSerialPlatform;

#ifdef __cplusplus
}
#endif

#endif // UXR_CLIENT_PROFILE_TRANSPORT_CUSTOM_RISCV_TRANSPORT_H_
