Convert Keras .h5 to Tensorflow .pb

```
  python3 h5_to_pb.py f.h5 f.pb
```

If use objects that are not recognized by Keras, do this change. For example, using tensorflow operations
  ```
    --- model = load_model(args.input_file_h5)
    +++ model = load_model(args.input_file_h5, custom_objects={'tf': tf})
  ```
