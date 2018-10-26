using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class forObject : MonoBehaviour
{
    public DefaultTrackableEventHandler EventHandler;
    public GameObject []obj = new GameObject[10];
    private Transform[] obj_transform = new Transform[10];
    private Rigidbody[] obj_rigidbody = new Rigidbody[10];
    private Vector3[] obj_position = new Vector3[10];
    private Quaternion[] obj_rotation = new Quaternion[10];

    private void Start()
    {
        for(int i = 0; i < obj.Length;i++)
        {
            obj_rigidbody[i] = obj[i].GetComponent<Rigidbody>();
            obj_transform[i] = obj[i].GetComponent<Transform>();
            obj_position[i]  = obj_transform[i].position;
            obj_rotation[i] = obj_transform[i].rotation;
            obj_rigidbody[i].useGravity = false;

        }
        //print("star obj_position[0]: " + obj_position[0] + "star obj_position[1]: " + obj_position[1] + "star obj_position[2]: " + obj_position[2]);

    }
    // Update is called once per frame
    void Update()
    {
        if (EventHandler.status == true)
        {
            for (int i = 0; i < obj.Length; i++)
            {
                obj_rigidbody[i].isKinematic = false;
                obj_rigidbody[i].useGravity = true;
            }
        }
        else
        {
            for (int i = 0; i < obj.Length; i++)
            {
                obj_rigidbody[i].isKinematic = true;
                obj_transform[i].rotation = obj_rotation[i];
                obj_transform[i].position = obj_position[i];
                //print("obj_transform[i].position: " + obj_transform[i].position + "obj_position[i]: " + obj_position[i]);
                obj_rigidbody[i].useGravity = false;

            }
        }
    }
}
