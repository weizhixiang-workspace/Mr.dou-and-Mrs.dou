using UnityEngine;
using System;
namespace HandPhysicsExtenstions
{
    [RequireComponent(typeof(HandPhysicsController))]
    public class HandPhysicsStandaloneInput : MonoBehaviour
    {
        public GameObject SerialportObject;
        public serialport script;
        public HandPhysicsController Controller;
        public int ThresholdOfBendLow = 24000;
        public int ThresholdOfBendHigh = 32000;
       
        public int ThresholdOfStopBendLow = 34000;
        public int ThresholdOfStopBendHigh = 44000;

        public bool LockCursor = true;
        public bool ControlsEnabled = true;

        [Header("Input Keys")]
        public string MoveForearmAxisX = "Mouse X";
        public string MoveForearmAxisY = "Mouse ScrollWheel";
        public string MoveForearmAxisZ = "Mouse Y";

        [Space]
        public string RotateForearmAxis = "Mouse X";
        public string RotateWristAxis = "Mouse Y";

        [Space]
        public KeyCode HoldRotation = KeyCode.Mouse1;

        public void OnApplicationFocus(bool focus)
        {
            if (focus && LockCursor)
                Cursor.lockState = CursorLockMode.Locked;
        }

        void Start()
        {
            script = SerialportObject.GetComponent<serialport>();
        }

        void Update()
        {
            if (!ControlsEnabled || !script.F03_valuesEnable)
                return;
         
            print("script.F03_values[0]:  "+script.F03_values[0] + "ThresholdOfBend:  "+ ThresholdOfBendHigh);
          
            if (ThresholdOfBendLow < script.F03_values[0] && script.F03_values[0] < ThresholdOfBendHigh)
                Controller.StartBendFinger(FingerType.Thumb);
            else if (ThresholdOfStopBendLow < script.F03_values[0]  && script.F03_values[0] < ThresholdOfStopBendHigh)
                Controller.StopBendFinger(FingerType.Thumb);

            if (ThresholdOfBendLow < script.F03_values[1] && script.F03_values[1] < ThresholdOfBendHigh)
                Controller.StartBendFinger(FingerType.Index);
            else if (ThresholdOfStopBendLow < script.F03_values[1] && script.F03_values[1] < ThresholdOfStopBendHigh)
                Controller.StopBendFinger(FingerType.Index);

            if (ThresholdOfBendLow < script.F03_values[2] && script.F03_values[2] < ThresholdOfBendHigh)
                Controller.StartBendFinger(FingerType.Middle);
            else if (ThresholdOfStopBendLow < script.F03_values[2] && script.F03_values[2] < ThresholdOfStopBendHigh)
                Controller.StopBendFinger(FingerType.Middle);

            if (ThresholdOfBendLow < script.F03_values[3] && script.F03_values[3] < ThresholdOfBendHigh)
                Controller.StartBendFinger(FingerType.Ring);
            else if (ThresholdOfStopBendLow < script.F03_values[3] && script.F03_values[3] < ThresholdOfStopBendHigh)
                Controller.StopBendFinger(FingerType.Ring);

            if (ThresholdOfBendLow < script.F03_values[4] && script.F03_values[4] < ThresholdOfBendHigh)
                Controller.StartBendFinger(FingerType.Pinky);
            else if (ThresholdOfStopBendLow < script.F03_values[4] && script.F03_values[4] < ThresholdOfStopBendHigh)
                Controller.StopBendFinger(FingerType.Pinky);

            if (!Input.GetKey(HoldRotation))
                Controller.MoveForearm(new Vector3(Input.GetAxis(MoveForearmAxisX), Input.GetAxis(MoveForearmAxisY),
                    Input.GetAxis(MoveForearmAxisZ)));
            else
            {
                Controller.RotateWrist(Input.GetAxis(RotateWristAxis));
                Controller.RotateForearm(Input.GetAxis(RotateForearmAxis));
            }
        }
    }
}

