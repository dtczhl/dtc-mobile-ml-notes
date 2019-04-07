package com.huanlezhang.tensorflowmobile;

import android.os.Debug;
import android.util.Log;

import org.tensorflow.Graph;
import org.tensorflow.Operation;
import org.tensorflow.contrib.android.TensorFlowInferenceInterface;

import java.util.Iterator;

class DtcTensorflowMobileHelper {

    static private final String TAG = "DTC Tensorflow Mobile Helper";

    static void printModelLayers(TensorFlowInferenceInterface tfInterface) {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(" \nML Model info: Layer name, size\n");
        Graph graph = tfInterface.graph();
        Iterator<Operation> iterator = graph.operations();
        while (iterator.hasNext()) {
            Operation operation = iterator.next();
            stringBuilder.append("\t" + operation.name()
                    + ", " + operation.output(0).shape().toString() + "\n");
        }
        Log.d(TAG, stringBuilder.toString());
    }

    static void runModelSISO(
            TensorFlowInferenceInterface tfInterface,
            String outputName, float[] outputData,
            String inputName, float[] inputData, long ... dims) {
        Log.d(TAG, "feed ML model input data");
        tfInterface.feed(inputName, inputData, dims);
        Log.d(TAG, "run ML model");
        tfInterface.run(new String[]{outputName});
        Log.d(TAG, "get ML model output data");
        tfInterface.fetch(outputName, outputData);
    }
}
