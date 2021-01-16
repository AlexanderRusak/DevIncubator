const setVoted=(votedObjectList, name, vote)=>{

    votedObjectList[name]?console.log("You have been already voted!"):votedObjectList[name]=vote;
    
  }

const voted={};
setVoted(voted,"Tanya","375333872713");
setVoted(voted,"Sasha","375298388602");
console.log(voted);
setVoted(voted,"Sasha","375298388602");
console.log(voted);
setVoted(voted,"Vasya","375292020327");
console.log(voted);