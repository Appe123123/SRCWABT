import React, { useState } from  "react";
import { HashRouter as Router, Route, Switch, Redirect } from "react-router-dom";
import Auth from "Auth";
//import Home from "Home";
//import Profile from "Profile";
//import Navigation from "Navigation";

const AppRouter = ({ isLoggedIn }) => {
    return (
        <Router>
            {isLoggedIn && <Navigation />}
            <Switch>
                {isLoggedIn ? (
                    <>
                        <Route exact path="/">
                            <Home />
                        </Route>
                        <Route exact path="/profile">
                            <Profile />
                        </Route>
                    </> 
                    ) : (
                    <>
                        <Route exact path="/">
                            <Auth />
                        </Route>
                    </>
                )}
            </Switch>
        </Router>
    );
};

export default AppRouter;