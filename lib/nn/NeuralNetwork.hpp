#pragma once

#include <cstdint>

namespace tflite {
    class Model;
    class MicroInterpreter;
    class ErrorReporter;

    template <unsigned int tOpCount>
    class MicroMutableOpResolver;
}

struct TfLiteTensor;

class NeuralNetwork {
public:
    NeuralNetwork();

    bool setUp();

    void tearDown();

    float predict(float number1, float number2);

private:
    uint8_t* _arena;
    const tflite::Model* _model;
    tflite::MicroMutableOpResolver<10>* _resolver;
    tflite::MicroInterpreter* _interpreter;
    tflite::ErrorReporter* _reporter;
    TfLiteTensor* _input;
    TfLiteTensor* _output;
};