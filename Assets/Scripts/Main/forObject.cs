using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class forObject : MonoBehaviour
{
    public DefaultTrackableEventHandler EventHandler;
    public GameObject Cube;
    public GameObject Capsule;
    private Rigidbody rigCube;
    private Rigidbody rigCapsule;
    private Transform traCube;
    private Transform traCapsule;
    private Vector3 positionOfCube;
    private void Start()
    {
        rigCube =  Cube.GetComponent<Rigidbody>();
        rigCapsule = Capsule.GetComponent<Rigidbody>();
        traCube = Cube.GetComponent<Transform>();
        traCapsule = Cube.GetComponent<Transform>();
        rigCube.useGravity = false;
        rigCapsule.useGravity = false;
    }
    // Update is called once per frame
    void Update()
    {
        if (EventHandler.status == true)
        {
            rigCube.useGravity = true;
            rigCapsule.useGravity = true;
        }
        else
        {
            rigCube.useGravity = false;
            rigCapsule.useGravity = false;
        }
    }
}
