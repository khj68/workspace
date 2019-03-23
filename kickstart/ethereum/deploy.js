const HDWalletProvider = require('truffle-hdwallet-provider');
const Web3 = require('web3');
const compiledFactory = require('./build/CampaignFactory.json');

const provider = new HDWalletProvider(
    'snake accident lawn tone token brand jealous spell lab squirrel mad treat',
    'https://rinkeby.infura.io/v3/1c9f0e3e016440e1a16a467f8aeb6efc'
);
const web3 = new Web3(provider);

const deploy = async()=>{
    const accounts = await web3.eth.getAccounts();

    console.log('Attempting to deploy from account', accounts[0]);

    const result = await new web3.eth.Contract(JSON.parse(compiledFactory.interface))
        .deploy({ data: '0x'+compiledFactory.bytecode })
        .send({ gas: '1000000', from: accounts[0] });


    console.log('Contract deployed to', result.options.address);
};
deploy();