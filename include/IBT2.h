/*
  IBT2.h - Library for IBT2 Motor Driver.
  Created by Usman Mehmood, September 26th, 2020.
*/

#ifndef IBT2_h
#define IBT2_h
#include "Arduino.h"

class IBT2
{
public:
    IBT2(
        const char EN_F[3], const char EN_B[3],
        const char PWM_F[3], const char PWM_B[3]);

    void Move_Forward();
    void Move_Backward();
    void Move_Left();
    void Move_Right();
    void Abdomen_Up();
    void Abdomen_Down();
    void Stop_Base();
    void Stop_Abdomen();

private:
    unsigned char _EN_F[3];
    unsigned char _EN_B[3];
    unsigned char _PWM_F[3];
    unsigned char _PWM_B[3];
};

IBT2::IBT2(
    const char EN_F[3], const char EN_B[3],
    const char PWM_F[3], const char PWM_B[3])
{
    for (int i = 0; i < 3; i++)
    {
        pinMode(EN_F[i], OUTPUT);
        _EN_F[i] = EN_F[i];
        pinMode(EN_B[i], OUTPUT);
        _EN_B[i] = EN_B[i];
        pinMode(PWM_F[i], OUTPUT);
        _PWM_F[i] = PWM_F[i];
        pinMode(PWM_B[i], OUTPUT);
        _PWM_B[i] = PWM_B[i];
    }
}

void IBT2::Move_Forward()
{
    digitalWrite(_EN_F[1], HIGH);
    digitalWrite(_EN_B[1], HIGH);
    digitalWrite(_EN_F[2], HIGH);
    digitalWrite(_EN_B[2], HIGH);
    analogWrite(_PWM_F[1], 150);
    analogWrite(_PWM_B[1], 0);
    analogWrite(_PWM_F[2], 150);
    analogWrite(_PWM_B[2], 0);
}

void IBT2::Move_Backward()
{
    digitalWrite(_EN_F[1], HIGH);
    digitalWrite(_EN_B[1], HIGH);
    digitalWrite(_EN_F[2], HIGH);
    digitalWrite(_EN_B[2], HIGH);
    analogWrite(_PWM_F[1], 0);
    analogWrite(_PWM_B[1], 150);
    analogWrite(_PWM_F[2], 0);
    analogWrite(_PWM_B[2], 150);
}

void IBT2::Move_Left()
{
    digitalWrite(_EN_F[1], HIGH);
    digitalWrite(_EN_B[1], HIGH);
    digitalWrite(_EN_F[2], HIGH);
    digitalWrite(_EN_B[2], HIGH);
    analogWrite(_PWM_F[1], 150);
    analogWrite(_PWM_B[1], 0);
    analogWrite(_PWM_F[2], 0);
    analogWrite(_PWM_B[2], 150);
}

void IBT2::Move_Right()
{
    digitalWrite(_EN_F[1], HIGH);
    digitalWrite(_EN_B[1], HIGH);
    digitalWrite(_EN_F[2], HIGH);
    digitalWrite(_EN_B[2], HIGH);
    analogWrite(_PWM_F[1], 0);
    analogWrite(_PWM_B[1], 150);
    analogWrite(_PWM_F[2], 150);
    analogWrite(_PWM_B[2], 0);
}

void IBT2::Abdomen_Up()
{
    digitalWrite(_EN_F[3], HIGH);
    digitalWrite(_EN_B[3], HIGH);
    analogWrite(_PWM_F[3], 150);
    analogWrite(_PWM_B[3], 0);
}

void IBT2::Abdomen_Down()
{
    digitalWrite(_EN_F[3], HIGH);
    digitalWrite(_EN_B[3], HIGH);
    analogWrite(_PWM_F[1], 150);
    analogWrite(_PWM_F[1], 150);
    analogWrite(_PWM_B[2], 150);
    analogWrite(_PWM_B[2], 150);
}

void IBT2::Stop_Base()
{
    analogWrite(_PWM_F[1], 0);
    analogWrite(_PWM_B[1], 0);
    analogWrite(_PWM_F[2], 0);
    analogWrite(_PWM_B[2], 0);
    digitalWrite(_EN_F[1], LOW);
    digitalWrite(_EN_B[1], LOW);
    digitalWrite(_EN_F[2], LOW);
    digitalWrite(_EN_B[2], LOW);
}

void IBT2::Stop_Abdomen()
{
    analogWrite(_PWM_F[3], 0);
    analogWrite(_PWM_B[3], 0);
    digitalWrite(_EN_F[3], LOW);
    digitalWrite(_EN_B[3], LOW);
}

#endif