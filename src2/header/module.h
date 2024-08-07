#pragma once

class Module {
public:
    Module() = default;  
    virtual bool init(){ 
        return true; 
    }
	virtual bool preUpdate(){ 
        return true; 
    }
	virtual bool update() = 0;
	virtual bool clear(){ 
        return true; 
    }
};