#include "zlac8015d.h"

#define FLIP -1

int main()
{
    printf("===begin===\n");
    ZLAC motorR;
    motorR.begin("/dev/ttyUSB0", 115200, 0x01);
    ZLAC motorL;
    motorL.begin("/dev/ttyUSB1", 115200, 0x01);

    printf("\n===set_vel_mode===\n");
    motorR.set_vel_mode();
    motorL.set_vel_mode();

    printf("\n===enable===\n");
    motorR.enable();
    motorL.enable();

    printf("\n===set_rpm===\n");
    motorR.set_rpm(50, "LEFT");
    motorR.set_rpm(50, "RIGHT");
    motorL.set_rpm(-50, "LEFT");
    motorL.set_rpm(-50, "RIGHT");

    printf("\n===set_sync_rpm===\n");

    printf("\n===disable===\n");
    motorR.disable();
    motorL.disable();
}
