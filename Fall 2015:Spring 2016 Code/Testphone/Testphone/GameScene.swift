//
//  GameScene.swift
//  Testphone
//
//  Created by Mario J Merendino on 12/4/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

import SpriteKit


class GameScene: SKScene {
    
    var bird=SKSpriteNode();
    
    override func didMoveToView(view: SKView) {
        //Physics
        self.physicsWorld.gravity = CGVectorMake(0.0 , -5.0);
        
        //Bird
        var BirdTexture = SKTexture(imageNamed: "bird")
        BirdTexture.filteringMode=SKTextureFilteringMode.Nearest;
        
        bird=SKSpriteNode(texture:BirdTexture)
        bird.setScale(0.5)
        bird.position = CGPoint(x: self.frame.size.width * 0.35, y:self.frame.size.height * 0.6);
        bird.physicsBody=SKPhysicsBody(circleOfRadius: bird.size.height/2)
        bird.physicsBody?.dynamic=true;
        bird.physicsBody?.allowsRotation=false;
        
        self.addChild(bird);
        
        //ground
        var groundtexture = SKTexture(imageNamed: "ground");
        var sprite = SKSpriteNode(texture: groundtexture);
        sprite.setScale(2.0);
        sprite.position=CGPointMake(sprite.size.width/2, sprite.size.height/2)
        self.addChild(sprite);
        
        var ground = SKNode();
        
        ground.position=CGPointMake(0, groundtexture.size().height)
        ground.physicsBody=SKPhysicsBody(rectangleOfSize: CGSizeMake(self.frame.width, groundtexture.size().height*2))
        ground.physicsBody?.dynamic=false;
        addChild(ground);

    }
    
    override func touchesBegan(touches: NSSet, withEvent event: UIEvent) {
        /* Called when a touch begins */
        
        for touch: AnyObject in touches {
            let location = touch.locationInNode(self);
            bird.physicsBody?.velocity=CGVectorMake(0,0);
            bird.physicsBody?.applyImpulse(CGVectorMake(0,25));

        }
    }
   
    override func update(currentTime: CFTimeInterval) {
        /* Called before each frame is rendered */
    }
}
