import React, { Component } from 'react';

// class MyName extends Component {
//   static defaultProps = {
//     name: 'default name'
//   }
  
//   render() {
//     return(
//       <div>
//         Hello! My name is <b>{this.props.name}</b>.
//       </div>
//     )
//   }
// }

const MyName = ({ name }) => {
  return (
    <div>
      Hello ! My name is {name}.
    </div>
  )
}

export default MyName;