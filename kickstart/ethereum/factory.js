import web3 from './web3'
import CampaignFactory from './build/CampaignFactory.json'

const instance = new web3.eth.Contract(
  JSON.parse(CampaignFactory.interface),
  '0x2Ad6DeE8a7d906e62A77fC74dD9326468E285147'
)

export default instance
