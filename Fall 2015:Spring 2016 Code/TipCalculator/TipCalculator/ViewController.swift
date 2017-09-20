//
//  ViewController.swift
//  TipCalculator
//
//  Created by Mario J Merendino on 12/27/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

import UIKit

class ViewController: UIViewController{

    @IBOutlet weak var billField: UITextField!
    @IBOutlet weak var tipLable: UILabel!
    @IBOutlet weak var totalLable: UILabel!
    @IBOutlet weak var tipControl: UISegmentedControl!
    override func viewDidLoad() {
        
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        tipLable.text="$0.00"
        totalLable.text="$0.00"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func oneditingchanged(sender: AnyObject) {
        var tippercents = [0.15, 0.20, 0.25]
        var tippercent = tippercents[tipControl.selectedSegmentIndex]
        
        
        
        var billAmount = NSString(string: billField.text!).doubleValue
        var tip = billAmount * tippercent
        var total = billAmount + tip

        tipLable.text = String(format: "$%.2f", tip)
        totalLable.text = String(format: "$%.2f", total)
        
    }
    @IBAction func onTap(sender: AnyObject) {
        view.endEditing(true)
    }

}

