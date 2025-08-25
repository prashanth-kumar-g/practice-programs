import {useState} from 'react';
const UserStatusSwitcher = () => { 
const [isOnline, setIsOnline] = useState(false); 
const toggleStatus = () => { 
setIsOnline((prevStatus) => !prevStatus); 
}; 
const statusStyle = { 
color: isOnline ? 'green' : 'red', 
fontWeight: 'bold', 
fontSize: '18px', 
margin: '10px 0' 
}; 
return ( 
<div style={{ textAlign: 'center', padding: '20px' }}> 
<p style={statusStyle}> 
Status: {isOnline ? 'Online' : 'Offline'} 
</p> 
<button onClick={toggleStatus}> 
Go {isOnline ? 'Offline' : 'Online'} 
</button> 
</div> 
); 
}; export default UserStatusSwitcher; 