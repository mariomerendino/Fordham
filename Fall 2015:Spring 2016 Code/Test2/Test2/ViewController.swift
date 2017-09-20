//
//  ViewController.swift
//  Test2
//
//  Created by Mario J Merendino on 8/29/16.
//  Copyright © 2016 Mario J Merendino. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var button1: UIButton!
    @IBOutlet weak var Label: UILabel!
    var num = 0
    
    @IBAction func plusTen(sender: AnyObject) {
        num = num + 10
        Label.text = String(num)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

