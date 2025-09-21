#pragma once

#define is_ball_close(distance) (distance > 350)
#define is_ball_far(distance) (distance < 300)

class Ball {
private:
    int p_angle{0}, p_distance{0};

public:
    int relative_angle{0}, absolute_angle{0};
    int distance{0}; // Bigger distance => closer ball
    bool seen{false};

    Ball();
    void read();
    void test();
};
