import { useState } from "react";

function Counter() { 
  const [count, setCount] = useState(0); 
 
  const increment = () => setCount(count + 1); 
  const decrement = () => setCount(count - 1); 
  const reset = () => setCount(0); 
 
  const containerStyle = { 
    textAlign: 'center', 
    marginTop: '50px', 
  }; 
  const buttonStyle = { 
    padding: '10px 20px', 
    margin: '0 10px', 
    backgroundColor: '#007bff', 
    color: 'white', 
    border: 'none', 
    borderRadius: '5px', 
    cursor: 'pointer', 
  }; 
  const countStyle = { 
    fontSize: '24px', 
    fontWeight: 'bold', 
    marginBottom: '20px', 
  }; 
  return ( 
    <div style={containerStyle}> 
      <div style={countStyle}>Count: {count}</div> 
      <button onClick={increment} style={buttonStyle}>Increase</button> 
      <button onClick={decrement} style={buttonStyle}>Decrease</button> 
      <button onClick={reset} style={buttonStyle}>Reset</button> 
    </div> 
  ); 
} export default Counter; 