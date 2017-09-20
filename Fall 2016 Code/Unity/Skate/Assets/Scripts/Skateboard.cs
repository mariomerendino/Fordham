using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Skateboard : MonoBehaviour {

	public float pushSpeed = 30.00f;
	public float currentSpeed = 0.00f;
	public float turnSpeed = 30.00f;
	public Rigidbody body;
	private Animator anim;

	// Use this for initialization
	void Start () {
		body= GetComponent<Rigidbody>();
		//anim = gameObject.GetComponentInChildren<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		
		//X Button, Push animation.
		if (Input.GetButton("X"))
		{
			Debug.Log("push");
			Vector3 direction = new Vector3(1f, 0f, 0f);
			body.velocity = direction * pushSpeed;

		}

		if (Input.GetButton ("B")) {
			Debug.Log ("Stop");
		}
		if (Input.GetButton ("A")) {
			Debug.Log ("A");
			//anim.SetInteger ("ollie", 1);
		}

		/*float turn = Input.GetAxis ("LeftJoyStickHorizontal");
		Vector3 turnVector = new Vector3 (0f, turn * turnSpeed, 0f);
		Quaternion deltaRotation = Quaternion.Euler(turn *Time.deltaTime);
		body.MoveRotation(body.rotation * deltaRotation);
		float mag = body.velocity.magnitude;
		body.velocity = transform.forward * mag;
		if (Input.GetButton ("Y")) {
			anim.SetInteger ("kickflip", 1);
		}
		//anim.SetInteger ("ollie", 0);
		//anim.SetInteger ("kickflip", 0);
		*/
	}
}
