pragma solidity ^0.4;

contract Study {
    address public seller;
    address public bidder;
    uint public initialSeed;
    uint public currentSeed;
    uint public limitTime;
    uint public publish;
    string public name;
    string public description;
    
    
    constructor (uint _publish, string _name, string _description,  uint _initialSeed/*, uint _limitTime*/) public {
       publish = _publish;
       name = _name;
       description = _description;
       seller = msg.sender;
       
       seller = msg.sender;
       initialSeed = _initialSeed * 100000000000000000;
       currentSeed = initialSeed;
    //   limitTime = now + _limitTime;
    }
    
    
    modifier exceedSeed {
        require(msg.value > currentSeed);
        _;
    }
    
    modifier onlySeller {
       require(msg.sender == seller);
       _;
    }
    
    function bid() public exceedSeed payable{
        require((msg.value % 100000000000000000) == 0);
        bidder.transfer(address(this).balance - msg.value);
        bidder = msg.sender;
        currentSeed = msg.value;
    }
    
    function biddingEnd() public onlySeller {
       require(now >= limitTime);
       seller.transfer(address(this).balance);
    }
} 