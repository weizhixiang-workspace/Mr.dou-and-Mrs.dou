using UnityEngine;

namespace HandPhysicsExtenstions
{
    [RequireComponent(typeof(Collider))]
    public class HandPart : MonoBehaviour
    {
        //public GameObject pickUp;
        //private void OnTriggerEnter(Collider other)
        //{
        //    Debug.Log("OnTriggerEnter");
        //    pickUp = other.gameObject;
        //    pickUp.transform.parent = this.transform;
        //    //pickUp.GetComponent<Rigidbody>().isKinematic = true;
        //}

        //private void OnTriggerExit(Collider other)
        //{
        //    Debug.Log("OnTriggerExit");
        //    pickUp = null;
        //}

        #region Component references
        /// <summary>
        /// Returns collider component attached to this hand part
        /// </summary>
        public Collider Collider
        {
            get
            {
                if (_collider == null)
                    _collider = GetComponent<Collider>();
                return _collider;
            }
        }
        private Collider _collider;

        /// <summary>
        /// Returns rigidbody component attached to this hand part
        /// </summary>
        public Rigidbody Rigidbody
        {
            get
            {
                if (_rigidbody == null)
                    _rigidbody = GetComponent<Rigidbody>();
                return _rigidbody;
            }
        }
        private Rigidbody _rigidbody;

        /// <summary>
        /// Returns configurable joint component of this hand part if attached
        /// </summary>
        public ConfigurableJoint Joint
        {
            get
            {
                if (_joint == null)
                    _joint = GetComponent<ConfigurableJoint>();
                return _joint;
            }
        }
        private ConfigurableJoint _joint;

        /// <summary>
        /// Returns <see cref="HandPhysicsController"/> which is controls this hand part
        /// </summary>
        public HandPhysicsController Controller { get; internal set; }
        #endregion
    }
}



