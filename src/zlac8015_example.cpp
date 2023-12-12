#include "motor_driver/zlac8015.h"

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

    // printf("\n===set_acc_decc_time===\n");
    // motorR.set_acc_time(500);
    // motorR.set_decc_time(500);
    // motorL.set_acc_time(500);
    // motorL.set_decc_time(500);

    printf("\n===enable===\n");
    motorR.enable();
    motorL.enable();

    printf("\n===set_rpm===\n");
    motorR.set_rpm(50, "LEFT");
    motorR.set_rpm(50, "RIGHT");
    motorL.set_rpm(-50, "LEFT");
    motorL.set_rpm(-50, "RIGHT");

    printf("\n===set_sync_rpm===\n");

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("i: %d read rpm R: %f \n", i, motorR.get_rpm());
    // }

    printf("\n===disable===\n");
    motorR.disable();
    motorL.disable();

    // printf("\n===get_error===\n");

    // motorR.get_error();
    // motorL.get_error();

    // printf("\n===set_vel_mode===\n");
    // motorR.set_vel_mode();
    //
    // motorR.set_acc_time(500);
    // motorR.set_decc_time(500);
    // motorR.max_speed(90);
    // motorR.initial_speed(40);

    // motorL.set_vel_mode();
    //
    // motorL.set_acc_time(500);
    // motorL.set_decc_time(500);
    // motorL.max_speed(90);
    // motorL.initial_speed(40);

    // printf("===set_rpm===");

    // motorL.set_rpm(10);
    // motorR.set_rpm(10);

    // for (int i = 0; i < 10000; i++)
    // {
    //     printf("i: %d read rpm R: %f \n", i, motorR.get_rpm() * FLIP);
    //     printf("i: %d read rpm L: %f \n", i, motorL.get_rpm());
    // }
    // motorR.disable();
    // motorL.disable();
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("i: %d read rpm R: %f \n", i, motorR.get_rpm() * FLIP);
    //     printf("i: %d read rpm L: %f \n", i, motorL.get_rpm());
    // }
    // motorR.enable();
    // motorL.enable();
    // motorL.set_rpm(-100);
    // motorR.set_rpm(-100 * FLIP);
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("i: %d read rpm R: %f \n", i, motorR.get_rpm() * FLIP);
    //     printf("i: %d read rpm L: %f \n", i, motorL.get_rpm());
    // }
    // motorR.disable();
    // motorL.disable();
}
