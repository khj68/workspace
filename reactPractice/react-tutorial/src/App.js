import React, { Component } from 'react';
import './App.css'
import MyName from './MyName';
import Counter from './Counter';

class App extends Component {
  render() {
    const name = 'react';
    const style = {
      backgroundColor: 'black',
      padding: '16px',
      color: 'white',
      fontSize: '12px'
    };
    return (
      <React.Fragment>
        <div className="App">
          <h1>hello {name}</h1>
        </div>
        <div style={{padding: '16px'}}>
          <h2>bye {name}</h2>
        </div>
        <MyName />
        <Counter />
      </React.Fragment>
    );
  }
}

export default App;
