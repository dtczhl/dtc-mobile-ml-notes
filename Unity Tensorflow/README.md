## Running Tensorflow Models in Unity


### Configuration

1.  install ML-Agents (windows)

  <https://github.com/Unity-Technologies/ml-agents/blob/master/docs/Installation-Windows.md>

2.  download TFSharpPlugin.unitypackage

  v0.5 version:
<https://s3.amazonaws.com/unity-ml-agents/0.5/TFSharpPlugin.unitypackage>

2.  create Unity project, in `Player Settings -> Other Settings`, add `ENABLE_TENSORFLOW` to `Scripting Define Symbols`

4.  run TFSharpPlugin.unitypackage and import all

5.  rename `.pb` to '.bytes'

### Example

1.  create `Models` folder under `Assets`. put `.bytes` tensorflow model in it

2.  code example
  ```
    public TextAsset graphModel;

    private float[,] inputTensor = new float[1, 100];
    private float[,] outputTensor = new float[1, 1];

        for (int i = 0; i < inputTensor.Length; i++) {
            inputTensor[0, i] = 2f;
        }

        using (var graph = new TFGraph())
        {
            graph.Import(graphModel.bytes);
            var session = new TFSession(graph);

            var runner = session.GetRunner();

            TFTensor input = inputTensor;

            runner.AddInput(graph["input_input"][0], input);

            runner.Fetch(graph["output/Sigmoid"][0]);

            outputTensor = runner.Run()[0].GetValue() as float[, ];

            Debug.Log(outputTensor[0, 0]);

            session.Dispose();
            graph.Dispose();
        }
  ```

### Reference
* Github: Syn-McJ/TFClassify-Unity. <https://github.com/Syn-McJ/TFClassify-Unity>
