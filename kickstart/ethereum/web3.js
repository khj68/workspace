import Web3 from "web3"

// const web3 = new Web3(window.web3.currentProvider);
let web3

if (typeof window !== "undefined" && typeof window.web3 !== "undefined") {
  // We are in the browser and metamask is running.
  web3 = new Web3(window.web3.currentProvider)
} else {
  //We are on the server OR the user is not running metamask
  const provider = new Web3.providers.HttpProvider(
    "https://rinkeby.infura.io/v3/1c9f0e3e016440e1a16a467f8aeb6efc"
  )
  web3 = new Web3(provider)
}

export default web3
