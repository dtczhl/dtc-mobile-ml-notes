
### Tensorflow Mobile Android App Config

1. `build.gradle (Module.app)`
    ```
        implementation 'org.tensorflow:tensorflow-android:+'
    ```

1. create `assets` folder
    ```
        app (right click) -> new-> folder -> Assets Folder
    ```

1. put `.pb` tensorflow model to the assets folder, load that model file
    ```
        AssetManager assetManager = getResources().getAssets();
        TensorFlowInferenceInterface tfInterface = new TensorFlowInferenceInterface(assetManager, "imdb.pb");
    ```

1. feed data, run model, and fetch result
    ```
        tfInterface.feed(inputName, inputData, dims)
        tfInterface.run(new String[]{outputName})
        tfInterface.fetch(outputName, outputData)
    ```

### Extras

`DtcTensorflowMobileHelper` is a wrapper class which includes some useful functions

A complete example with a ML model (input: an array of 100, output: a single value)

```
    AssetManager assetManager = getResources().getAssets();
    TensorFlowInferenceInterface tfInterface = new TensorFlowInferenceInterface(assetManager, "imdb.pb");

    DtcTensorflowMobileHelper.printModelLayers(tfInterface);

    float[] inputData = new float[100];
    for (int i = 0; i < inputData.length; i++) {
        inputData[i] = 2f;
    }

    float[] outputResult = new float[1];

    DtcTensorflowMobileHelper.runModelSISO(tfInterface, "output/Sigmoid", outputResult,
            "input_input", inputData, 1, 100);

    Log.d(TAG, Float.toString(outputResult[0]));
```