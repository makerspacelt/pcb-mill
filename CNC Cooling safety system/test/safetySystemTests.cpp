#include <unity.h>
#include <../src/safetySystem.hpp>

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void countMacroWorks()
{
    int sizeOfArray = 5;
    float someArray[sizeOfArray];

    TEST_ASSERT_EQUAL(sizeOfArray, COUNT_OF_FLOAT(someArray));
}

void isAllSensorsPresent_True_CountEquals()
{
    int count = SENSOR_COUNT;
    TEST_ASSERT_TRUE(IsAllSensorsPresent(count));
}
void isAllSensorsPresent_True_CountDiffers()
{
    TEST_ASSERT_FALSE(IsAllSensorsPresent(5));
}
void GetTemperature_ReturnsNegativeIfOutOfBounds()
{
    float someArray[2]{0};
    unsigned int outOfBoundsIndex = 5;
    float actualTemperature = GetTemperature(outOfBoundsIndex, someArray);
    TEST_ASSERT_EQUAL_FLOAT(INVALID_TEMPERATURE, actualTemperature);
}

void GetTemperature_ReturnsTemperatureByIndex()
{
    float someArray[2]{0};
    float expectedT = 15.3;
    unsigned int index = 1;
    someArray[index] = expectedT;
    TEST_ASSERT_EQUAL_FLOAT(expectedT, GetTemperature(index, someArray));
}

void GetSpindleTemperature_ReturnsSpindleIndexTemp()
{
    float someArray[2]{0};
    float expectedT = 15.3;
    unsigned int index = SPINDLE_SENSOR_INDEX;
    someArray[index] = expectedT;
    TEST_ASSERT_EQUAL_FLOAT(expectedT, GetSpindleTemperature(someArray));
}
void GetCoolantTemperature_ReturnsCoolantIndexTemp()
{
    float someArray[2]{0};
    float expectedT = 15.3;
    unsigned int index = COOLANT_SENSOR_INDEX;
    someArray[index] = expectedT;
    TEST_ASSERT_EQUAL_FLOAT(expectedT, GetCoolantTemperature(someArray));
}

#pragma region IsTemperatureInBounds
void IsTemperatureInBounds_False_TOverMaxBound()
{
    float maxBound = 5;
    float temperature = maxBound + 1;
    TEST_ASSERT_FALSE(IsTemperatureInBounds(temperature, maxBound));
}
void IsTemperatureInBounds_False_TLowerMIN_TEMP()
{
    float maxBound = 5;
    float temperature = MIN_TEMP;
    TEST_ASSERT_FALSE(IsTemperatureInBounds(temperature, maxBound));
}
void IsTemperatureInBounds_True_InBounds()
{
    float maxBound = 10;
    float temperature = 5;
    TEST_ASSERT_TRUE(IsTemperatureInBounds(temperature, maxBound));
}
#pragma endregion

#pragma region IsSpindleOverheated
void IsSpindleOverheated_True_TOverMaxBound()
{
    float maxBound = SPINDLE_MAX_TEMP;
    float temperature = maxBound + 1;
    TEST_ASSERT_TRUE(IsSpindleOverheated(temperature));
}
void IsSpindleOverheated_True_TLowerMIN_TEMP()
{
    float temperature = MIN_TEMP;
    TEST_ASSERT_TRUE(IsSpindleOverheated(temperature));
}
void IsSpindleOverheated_False_InBounds()
{
    float temperature = 5;
    TEST_ASSERT_FALSE(IsSpindleOverheated(temperature));
}

#pragma endregion

#pragma region IsCoolantOverheated
void IsCoolantOverheated_True_TOverMaxBound()
{
    float maxBound = COOLANT_MAX_TEMP;
    float temperature = maxBound + 1;
    TEST_ASSERT_TRUE(IsCoolantOverheated(temperature));
}
void IsCoolantOverheated_True_TLowerMIN_TEMP()
{
    float temperature = MIN_TEMP;
    TEST_ASSERT_TRUE(IsCoolantOverheated(temperature));
}
void IsCoolantOverheated_False_InBounds()
{
    float temperature = 5;
    TEST_ASSERT_FALSE(IsCoolantOverheated(temperature));
}
#pragma endregion

#pragma region MainCheck

void IsSystemFailure_True_SensorLoss()
{
    int sensorCount = SENSOR_COUNT;
    float temperatures[sensorCount]{10}; // init in bounds
    TEST_ASSERT_TRUE(IsSystemFailure(temperatures, sensorCount - 1));
}

void IsSystemFailure_True_SpindleOverHeat()
{
    float temperatures[SENSOR_COUNT]{10}; // init in bounds
    temperatures[SPINDLE_SENSOR_INDEX] = SPINDLE_MAX_TEMP + 1;
    TEST_ASSERT_TRUE(IsSystemFailure(temperatures, SENSOR_COUNT));
}
void IsSystemFailure_True_CoolantOverHeat()
{
    float temperatures[SENSOR_COUNT]{10}; // init in bounds
    temperatures[COOLANT_SENSOR_INDEX] = COOLANT_MAX_TEMP + 1;
    TEST_ASSERT_TRUE(IsSystemFailure(temperatures, SENSOR_COUNT));
}

#pragma endregion

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(isAllSensorsPresent_True_CountEquals);
    RUN_TEST(isAllSensorsPresent_True_CountDiffers);

    RUN_TEST(countMacroWorks);

    RUN_TEST(GetTemperature_ReturnsNegativeIfOutOfBounds);
    RUN_TEST(GetTemperature_ReturnsTemperatureByIndex);

    RUN_TEST(GetSpindleTemperature_ReturnsSpindleIndexTemp);
    RUN_TEST(GetCoolantTemperature_ReturnsCoolantIndexTemp);

    RUN_TEST(IsTemperatureInBounds_False_TOverMaxBound);
    RUN_TEST(IsTemperatureInBounds_False_TLowerMIN_TEMP);
    RUN_TEST(IsTemperatureInBounds_True_InBounds);

    RUN_TEST(IsSpindleOverheated_True_TOverMaxBound);
    RUN_TEST(IsSpindleOverheated_True_TLowerMIN_TEMP);
    RUN_TEST(IsSpindleOverheated_False_InBounds);

    RUN_TEST(IsCoolantOverheated_True_TOverMaxBound);
    RUN_TEST(IsCoolantOverheated_True_TLowerMIN_TEMP);
    RUN_TEST(IsCoolantOverheated_False_InBounds);

    RUN_TEST(IsSystemFailure_True_SensorLoss);
    RUN_TEST(IsSystemFailure_True_SpindleOverHeat);
    RUN_TEST(IsSystemFailure_True_CoolantOverHeat);

    UNITY_END();
}