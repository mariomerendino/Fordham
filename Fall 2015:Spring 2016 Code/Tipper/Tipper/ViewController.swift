//
//  ViewController.swift
//  Tipper
//
//  Created by Mario J Merendino on 12/31/15.
//  Copyright © 2015 Mario J Merendino. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var billField: UITextField!
    @IBOutlet weak var tipLabel: UILabel!
    @IBOutlet weak var totalLabel: UILabel!
    @IBOutlet weak var tipControl: UISegmentedControl!
    override func viewDidLoad() {
        super.viewDidLoad()
        tipLabel.text="$0.00"
        totalLabel.text="$0.00"
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func OnEditingChanged(sender: AnyObject) {
        var tippercents = [0.15, 0.20, 0.25]
        var tippercent = tippercents[tipControl.selectedSegmentIndex]
        
        
        
        var billAmount = NSString(string: billField.text!).doubleValue
        var tip = billAmount * tippercent
        var total = billAmount + tip
        
        tipLabel.text = String(format: "$%.2f", tip)
        totalLabel.text = String(format: "$%.2f", total)
        
    }

    @IBAction func OnTap(sender: AnyObject) {
            view.endEditing(true)
    }
}

