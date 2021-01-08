import React, { useState } from  "react";
import { authService, firebaseInstance } from "Base";

const Auth =  () => {
    const [ID, setID] = useState("");
    const [password, setPassword ] = useState("");
    const [newAccount, setNewAccount ] = useState(true);
    const [error, setError] = useState("");
    const onChange = (event) => {
        const {
            target: {name,value},
        } = event;
        if (name === "ID") {
            setEmail(value);
        } else if ( name === "password" ){
            setPassword(value);
        }
    };
    const onSubmit = async (event) => {
        event.preventDefault();
        try{
            let data;
            if(newAccount){
                data = await authService.createUserWithEmailAndPassword(email, password);
            } else {
                data = await authService.signInWithEmailAndPassword(email,password);
            }
            console.log(data);
        } catch (error) {
            setError(error.message);
        }
    }; 
    const toggleAccount = () => setNewAccount(prev => !prev);
    const onSocialClick = async (event) => {
        const {target: {name}} = event;
    }
    return (
        <div>
            <form onSubmit={onSubmit}>
                <input name="ID" type="text" placeholder="IDD" required value={email} onChange={onChange}/>
                <input name="password" type="password" placeholder="Password" required value={password} onChange={onChange}/>
                <input type="submit" value={newAccount ? "Create Account" : "Log In"} />
                {error}
            </form>
            <span onClick={toggleAccount}>{newAccount ? "Sign In" : "Create Account"}</span>
        </div>
    );
};

export default Auth;